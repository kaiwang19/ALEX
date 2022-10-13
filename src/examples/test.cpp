// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

/*
 * This short sample program demonstrates ALEX's API.
 */

#include "../core/alex.h"
#include "print.h"
#include <vector>


#include <fstream>
#include <iostream>
#include <stack>
#include <type_traits>

// #define KEY_TYPE int
// #define PAYLOAD_TYPE int

#define KEY_TYPE uint64_t     
#define PAYLOAD_TYPE uint64_t

int main(int, char**) 
{
  std::vector<KEY_TYPE> Insert_List = 
    // {0, 50, 2, 4, 6, 7, 8, 10, 12, 13, 15,
  	// 16,	20,	23,	26,	30,
    // 31,	32,	33,	34,	35,	36,	37,	38,	39,	40,	41,	42,	43,	44,	45};

    {1, 2, 4, 6, 7, 10, 12, 13, 15,	
  	16, 20,	23,	27,	
    30, 31,	32,	33,	34,	35,	36,	37,	38,	39,	40,	41,	42,	43,	44,	45};


    // {0, 2, 4, 6, 8, 10, 12, 14, 16,	
  	// 17, 20,	23,	26,	29,
    // 30, 31,	32,	33,	34,	35,	36,	37,	38,	39,	40,	41,	42,	43,	44};

    // {0, 44, 
    // 2, 4, 6, 8, 10, 12, 14, 16,	
  	// 17, 20,	23,	26,	29,
    // 30, 31,	32,	33,	34,	35,	36,	37,	38,	39,	40,	41,	42,	43};


  // std::vector<KEY_TYPE> Insert_List = {0, 5};
    
  // for(int i=10; i<450; i=i+5)
  // {
  //   Insert_List.push_back(i);
  // }
    
  // for(int i=450; i<1000; i=i+10)
  // {
  //   Insert_List.push_back(i);
  // }
  // Insert_List.push_back(1000);




  // const std::vector<KEY_TYPE> Insert_List = 
  // {10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100,
  // 10, 20, 30, 40, 50, 60, 70, 80, 90, 15, 25, 35, 45, 55, 65, 75, 85, 95, 100};

  std::mt19937_64 gen(std::random_device{}());
  std::uniform_int_distribution<PAYLOAD_TYPE> dis;

  alex::Alex<KEY_TYPE, PAYLOAD_TYPE> index;

  for (int i = 0; i < (int)Insert_List.size(); i++) {
    KEY_TYPE new_key = Insert_List[i];
    PAYLOAD_TYPE new_payload = dis(gen);
    index.insert(new_key, new_payload);

    // alex::AlexDataNode<KEY_TYPE, PAYLOAD_TYPE>* temp_node = index.last_data_node();
    // temp_node->print(true);
    // index.print_istats_();
    // std::cout << "=====" << std::endl;

    
    // check sth after inserting 
    // std::cout << " ==== After inserting " << i+1 << " keys: " << Insert_List[i] << "\n"
    //         << " num_model_nodes " << index.get_stats().num_model_nodes
    //         << " num_data_nodes " << index.get_stats().num_data_nodes
    //         << " -->  [root node] a_ " << index.root_node_->model_.a_
    //         << " b_ " << index.root_node_->model_.b_
    //         << std::endl;
    // alex::AlexDataNode<KEY_TYPE, PAYLOAD_TYPE>* temp_node = index.first_data_node();
    // temp_node->print();
    // while(temp_node->next_leaf_ != nullptr)
    // {
    //   temp_node = temp_node->next_leaf_;
    //   temp_node->print();
    // }
    // ALEX_PRINT("");

  }

  index.print_istats_();

  std::cout << " check max_data_node_slots " << index.derived_params_.max_data_node_slots
            << " max_fanout " << index.derived_params_.max_fanout
            << " KEY_TYPE " << sizeof(KEY_TYPE)
            << " PAYLOAD_TYPE " << sizeof(PAYLOAD_TYPE)
            << " pair " << sizeof(std::pair<KEY_TYPE, PAYLOAD_TYPE>)
            << std::endl;

    ALEX_PRINT("");
    alex::AlexDataNode<KEY_TYPE, PAYLOAD_TYPE>* temp_node = index.first_data_node();
    temp_node->print();
    while(temp_node->next_leaf_ != nullptr)
    {
      temp_node = temp_node->next_leaf_;
      temp_node->print();
    }
    ALEX_PRINT("");

  alex::AlexDataNode<KEY_TYPE, PAYLOAD_TYPE>* leaf_node = index.first_data_node();
  printStructureUINT64(leaf_node);


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
