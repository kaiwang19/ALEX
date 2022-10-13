// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#include "../core/alex.h"

auto to_bytes(std::uint64_t x)
{
    std::array<std::uint8_t, 8> b;
    b[0] = x >> 8*0;
    b[1] = x >> 8*1;
    b[2] = x >> 8*2;
    b[3] = x >> 8*3;
    b[4] = x >> 8*4;
    b[5] = x >> 8*5;
    b[6] = x >> 8*6;
    b[7] = x >> 8*7;
    return b;
}

auto int_to_string(std::uint64_t x)
{
    std::string out = "hhh";
    std::array<std::uint8_t, 8> b;

    b[0] = x >> 8*0;
    b[1] = x >> 8*1;
    b[2] = x >> 8*2;
    b[3] = x >> 8*3;
    b[4] = x >> 8*4;
    b[5] = x >> 8*5;
    b[6] = x >> 8*6;
    b[7] = x >> 8*7;

    out += b[0];   out += "-";
    out += b[1];   out += "-";
    out += b[2];   out += "-";
    out += b[3];   out += "-";
    out += b[4];   out += "-";
    out += b[5];   out += "-";
    out += b[6];   out += "-";
    out += b[7];   out += "-";

  std::cout << b[0] << std::endl;  
  std::cout << b[1] << std::endl;  
  std::cout << b[2] << std::endl;  
  std::cout << b[3] << std::endl;  
  std::cout << b[4] << std::endl;  
  std::cout << b[5] << std::endl;  
  std::cout << b[6] << std::endl;  
  std::cout << b[7] << std::endl;  

    return out;
}


// Look at some stats
void printStat(alex::Alex<int, int>::Stats stats)
{
  std::cout << "******** Overall ********" 
            << std::endl;  
  std::cout << "Num keys: " << stats.num_keys
            << std::endl;  // expected: 199
  std::cout << "Num Model Nodes: " << stats.num_model_nodes
            << std::endl;  
  std::cout << "Num Data Nodes: " << stats.num_data_nodes
            << std::endl;  

  std::cout << "******** Model Nodes ********" 
            << std::endl;  
  std::cout << "Num model_node_expansions: " << stats.num_model_node_expansions
            << std::endl;  
  std::cout << "Num model_node_splits: " << stats.num_model_node_splits
            << std::endl;  
  std::cout << "Num model_node_expansion_pointers: " << stats.num_model_node_expansion_pointers
            << std::endl;  
  std::cout << "Num model_node_split_pointers: " << stats.num_model_node_split_pointers
            << std::endl;  

  std::cout << "******** Data Nodes ********" 
            << std::endl;  
  std::cout << "Num expand_and_scales: " << stats.num_expand_and_scales
            << std::endl;  
  std::cout << "Num expand_and_retrains: " << stats.num_expand_and_retrains
            << std::endl;  
  std::cout << "Num downward_splits: " << stats.num_downward_splits
            << std::endl;  
  std::cout << "Num sideways_splits: " << stats.num_sideways_splits
            << std::endl;  
  std::cout << "Num downward_split_keys: " << stats.num_downward_split_keys
            << std::endl;  
  std::cout << "Num sideways_split_keys: " << stats.num_sideways_split_keys
            << std::endl;  
  std::cout << "Num node_lookups: " << stats.num_node_lookups
            << std::endl;  
  std::cout << "Num lookups: " << stats.num_lookups
            << std::endl;  
  std::cout << "Num inserts: " << stats.num_inserts
            << std::endl;  // expected: 109

  std::cout << "******** Time ********" 
            << std::endl;  
  std::cout << "splitting_time: " << stats.splitting_time
            << std::endl;  
  std::cout << "cost_computation_time: " << stats.cost_computation_time
            << std::endl;  
  std::cout << "******** The End of stats. ********" 
            << std::endl;  
}

// Check the index structure
void printStructure(alex::AlexDataNode<int, int>* leaf_node)
{
  while(leaf_node->next_leaf_ != nullptr)
  {
    std::cout << " level " << leaf_node->level_
            << " num_keys " << leaf_node->num_keys_
            << " bitmap " << *leaf_node->bitmap_
            << " capacity " << leaf_node->data_capacity_
            << " size " << leaf_node->data_size()
            << " first_key " << leaf_node->first_key()
            << " first_pos " << leaf_node->first_pos()
            << " last_key " << leaf_node->last_key()
            << " last_pos " << leaf_node->last_pos()
            << " a " << leaf_node->model_.a_
            << " b " << leaf_node->model_.b_
            << std::endl;
    leaf_node = leaf_node->next_leaf_;
  }

  std::cout << " level " << leaf_node->level_
            << " num_keys " << leaf_node->num_keys_
            << " bitmap " << *leaf_node->bitmap_
            << " capacity " << leaf_node->data_capacity_
            << " size " << leaf_node->data_size()
            << " first_key " << leaf_node->first_key()
            << " first_pos " << leaf_node->first_pos()
            << " last_key " << leaf_node->last_key()
            << " last_pos " << leaf_node->last_pos()
            << " a " << leaf_node->model_.a_
            << " b " << leaf_node->model_.b_
            << "\n" << std::endl;
}

// Check the index structure
void printStructureUINT64(alex::AlexDataNode<uint64_t, uint64_t>* leaf_node)
{
  while(leaf_node->next_leaf_ != nullptr)
  {
    std::cout << " level " << leaf_node->level_
            << " num_keys " << leaf_node->num_keys_
            << " bitmap " << *leaf_node->bitmap_
            << " capacity " << leaf_node->data_capacity_
            << " size " << leaf_node->data_size()
            << " first_key " << leaf_node->first_key()
            << " first_pos " << leaf_node->first_pos()
            << " last_key " << leaf_node->last_key()
            << " last_pos " << leaf_node->last_pos()
            << " a " << leaf_node->model_.a_
            << " b " << leaf_node->model_.b_
            << std::endl;
    leaf_node = leaf_node->next_leaf_;
  }

  std::cout << " level " << leaf_node->level_
            << " num_keys " << leaf_node->num_keys_
            << " bitmap " << *leaf_node->bitmap_
            << " capacity " << leaf_node->data_capacity_
            << " size " << leaf_node->data_size()
            << " first_key " << leaf_node->first_key()
            << " first_pos " << leaf_node->first_pos()
            << " last_key " << leaf_node->last_key()
            << " last_pos " << leaf_node->last_pos()
            << " a " << leaf_node->model_.a_
            << " b " << leaf_node->model_.b_
            << "\n" << std::endl;
}

// Check the index structure
void printStructureDouble(alex::AlexDataNode<double, double>* leaf_node)
{
  while(leaf_node->next_leaf_ != nullptr)
  {
    std::cout << " level " << leaf_node->level_
            << " num_keys " << leaf_node->num_keys_
            << " bitmap " << *leaf_node->bitmap_
            << " capacity " << leaf_node->data_capacity_
            << " size " << leaf_node->data_size()
            << " first_key " << leaf_node->first_key()
            << " first_pos " << leaf_node->first_pos()
            << " last_key " << leaf_node->last_key()
            << " last_pos " << leaf_node->last_pos()
            << " a " << leaf_node->model_.a_
            << " b " << leaf_node->model_.b_
            << std::endl;
    leaf_node = leaf_node->next_leaf_;
  }

  std::cout << " level " << leaf_node->level_
            << " num_keys " << leaf_node->num_keys_
            << " bitmap " << *leaf_node->bitmap_
            << " capacity " << leaf_node->data_capacity_
            << " size " << leaf_node->data_size()
            << " first_key " << leaf_node->first_key()
            << " first_pos " << leaf_node->first_pos()
            << " last_key " << leaf_node->last_key()
            << " last_pos " << leaf_node->last_pos()
            << " a " << leaf_node->model_.a_
            << " b " << leaf_node->model_.b_
            << "\n" << std::endl;
}