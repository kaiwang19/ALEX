// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

/*
 * This short sample program demonstrates ALEX's API.
 */

#include "../core/alex.h"
#include "print.h"
#include <vector>

#define KEY_TYPE double     
#define PAYLOAD_TYPE double
#define BulkLoad_Num 20
// #define Insert_Num 4 
#define Insert_Num 0

int main(int, char**) {
  // Create some synthetic data
  // const std::vector<KEY_TYPE> BulkLoad_List = 
  // {
  //   0.00, 0.04, 0.08, 0.12, 0.16, 0.18, 0.24,   
  //   0.25, 0.26, 0.27, 0.28, 0.29, 0.30, 0.36, 0.38, 0.40, 0.45, 
  //   0.50, 0.60, 0.70, 0.80, 0.90, 1.00
  // };
  
  const std::vector<KEY_TYPE> BulkLoad_List = 
  {
    0.00, 0.08, 0.20, 0.25, 
    0.251, 0.252, 0.253, 0.254, 0.255, 0.256, 
    0.36, 0.362, 0.42, 0.422, 0.424,  
    0.46, 0.50, 0.60, 0.80, 1.00
  };
  
  // const std::vector<KEY_TYPE> Insert_List = {1.1, 2.1, 3.1, 4.1};
  const std::vector<KEY_TYPE> Insert_List = {};

  std::pair<KEY_TYPE, PAYLOAD_TYPE> values[BulkLoad_Num];

  std::mt19937_64 gen(std::random_device{}());
  std::mt19937_64 gen_payload(std::random_device{}());

  for (int i = 0; i < BulkLoad_Num; i++) {
    values[i].first = BulkLoad_List[i];
    values[i].second = static_cast<PAYLOAD_TYPE>(gen_payload());
  }

  // std::shuffle(values, values + num_keys, std::default_random_engine{});

  alex::Alex<KEY_TYPE, PAYLOAD_TYPE> index;

  std::cout << " check max_data_node_slots " << index.derived_params_.max_data_node_slots
            << " max_fanout " << index.derived_params_.max_fanout
            << " KEY_TYPE " << sizeof(KEY_TYPE)
            << " PAYLOAD_TYPE " << sizeof(PAYLOAD_TYPE)
            << std::endl;

  // Bulk load the keys
  index.bulk_load(values, BulkLoad_Num);
  
  // check sth after bulk loading 
  std::cout << " ==== After bulk load \n"
            << " num_model_nodes " << index.get_stats().num_model_nodes
            << " num_data_nodes " << index.get_stats().num_data_nodes
            << " -->  [root node] a_ " << index.root_node_->model_.a_
            << " b_ " << index.root_node_->model_.b_
            << std::endl;
  alex::AlexDataNode<KEY_TYPE, PAYLOAD_TYPE>* leaf_node = index.first_data_node();
  printStructureDouble(leaf_node);

  // Insert the keys after bulk loading.
  for (int i = 0; i < Insert_Num; i++) {
    KEY_TYPE new_key = Insert_List[i];
    PAYLOAD_TYPE new_payload = static_cast<PAYLOAD_TYPE>(gen_payload());
    index.insert(new_key, new_payload);
    
    // check sth after inserting 
    std::cout << " ==== After inserting " << i+1 << " keys: " << Insert_List[i] << "\n"
            << " num_model_nodes " << index.get_stats().num_model_nodes
            << " num_data_nodes " << index.get_stats().num_data_nodes
            << " -->  [root node] a_ " << index.root_node_->model_.a_
            << " b_ " << index.root_node_->model_.b_
            << std::endl;
    alex::AlexDataNode<KEY_TYPE, PAYLOAD_TYPE>* temp_node = index.first_data_node();
    printStructureDouble(temp_node);
  }




  // // Erase the keys [0, 10). Now there are 190 keys.
  // for (int i = 0; i < 10; i++) {
  //   index.erase(i);
  // }

  // // Iterate through all entries in the index and update their payload if the
  // // key is even
  // int num_entries = 0;
  // for (auto it = index.begin(); it != index.end(); it++) {
  //   if (it.key() % 2 == 0) {  // it.key() is equivalent to (*it).first
  //     it.payload() = dis(gen);
  //   }
  //   num_entries++;
  // }
  // if (num_entries != 190) {
  //   std::cout << "Error! There should be 190 entries in the index."
  //             << std::endl;
  // }

  // // Iterate through all entries with keys between 50 (inclusive) and 100
  // // (exclusive)
  // num_entries = 0;
  // for (auto it = index.lower_bound(50); it != index.lower_bound(100); it++) {
  //   num_entries++;
  // }
  // if (num_entries != 50) {
  //   std::cout
  //       << "Error! There should be 50 entries with keys in the range [50, 100)."
  //       << std::endl;
  // }

  // // Equivalent way of iterating through all entries with keys between 50
  // // (inclusive) and 100 (exclusive)
  // num_entries = 0;
  // auto it = index.lower_bound(50);
  // while (it.key() < 100 && it != index.end()) {
  //   num_entries++;
  //   it++;
  // }
  // if (num_entries != 50) {
  //   std::cout
  //       << "Error! There should be 50 entries with keys in the range [50, 100)."
  //       << std::endl;
  // }

  // // Insert 9 more keys with value 42. Now there are 199 keys.
  // for (int i = 0; i < 9; i++) {
  //   KEY_TYPE new_key = 42;
  //   PAYLOAD_TYPE new_payload = dis(gen);
  //   index.insert(new_key, new_payload);
  // }

  // // Iterate through all 10 entries with keys of value 42
  // int num_duplicates = 0;
  // for (auto it = index.lower_bound(42); it != index.upper_bound(42); it++) {
  //   num_duplicates++;
  //   // std::cout
  //   //     << "payload for key 42 "  << it.payload()
  //   //     << std::endl;
  // }
  // if (num_duplicates != 10) {
  //   std::cout << "Error! There should be 10 entries with key of value 42."
  //             << std::endl;
  // }

  // // Check if a non-existent key exists
  // it = index.find(1337);
  // if (it != index.end()) {
  //   std::cout << "Error! Key with value 1337 should not exist." << std::endl;
  // }

  // // Look at some stats
  // auto stats = index.get_stats();
  // // std::cout << "Final num keys: " << stats.num_keys
  // //           << std::endl;  // expected: 199
  // // std::cout << "Num inserts: " << stats.num_inserts
  // //           << std::endl;  // expected: 109
  // printStat(stats);
}
