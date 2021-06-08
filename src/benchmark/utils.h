// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#include "zipf.h"

template <class T>
bool load_binary_data(T data[], int length, const std::string& file_path) {
  std::ifstream is(file_path.c_str(), std::ios::binary | std::ios::in);
  if (!is.is_open()) {
    return false;
  }
  is.read(reinterpret_cast<char*>(data), std::streamsize(length * sizeof(T)));
  is.close();
  return true;
}

template <class T>
bool load_text_data(T array[], int length, const std::string& file_path) {
  std::ifstream is(file_path.c_str());
  if (!is.is_open()) {
    return false;
  }
  int i = 0;
  std::string str;
  while (std::getline(is, str) && i < length) {
    std::istringstream ss(str);
    ss >> array[i];
    i++;
  }
  is.close();
  return true;
}

template <class T>
T* get_search_keys(T array[], int num_keys, int num_searches) {
  std::mt19937_64 gen(std::random_device{}());
  std::uniform_int_distribution<int> dis(0, num_keys - 1);
  auto* keys = new T[num_searches];
  for (int i = 0; i < num_searches; i++) {
    int pos = dis(gen);
    keys[i] = array[pos];
  }
  return keys;
}

template <class T>
T* get_search_keys_zipf(T array[], int num_keys, int num_searches) {
  auto* keys = new T[num_searches];
  ScrambledZipfianGenerator zipf_gen(num_keys);
  for (int i = 0; i < num_searches; i++) {
    int pos = zipf_gen.nextValue();
    keys[i] = array[pos];
  }
  return keys;
}

// Look at some stats
void printStat_Double(alex::Alex<double, double>::Stats stats)
{
  std::cout << "Num keys: " << stats.num_keys
            << std::endl;  
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
            << std::endl; 

  std::cout << "******** Time ********" 
            << std::endl;  
  std::cout << "splitting_time: " << stats.splitting_time / 1e9 << " secs."
            << std::endl;  
  std::cout << "cost_computation_time: " << stats.cost_computation_time / 1e9 << " secs."
            << std::endl;  
}

// Look at some stats
void printStat_Int64(alex::Alex<uint64_t, uint64_t>::Stats stats)
{
  std::cout << "Num keys: " << stats.num_keys
            << std::endl; 
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
            << std::endl;  

  std::cout << "******** Time ********" 
            << std::endl;  
  std::cout << "splitting_time: " << stats.splitting_time / 1e9 << " secs."
            << std::endl;  
  std::cout << "cost_computation_time: " << stats.cost_computation_time / 1e9 << " secs."
            << std::endl;  
}