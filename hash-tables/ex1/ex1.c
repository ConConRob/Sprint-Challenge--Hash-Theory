#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *create_answer(int index_1, int index_2){
   Answer *answer = malloc(sizeof(Answer));
   answer->index_1 = index_1;
   answer->index_2 = index_2;
   return answer;
}

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  /* YOUR CODE HERE */
  // store all weights in table
  for (int i = 0; i < length; i++)
  {
    hash_table_insert(ht, weights[i], i);
  }
  // try every weight up to length
  for(int s_weight = 0; s_weight<limit; s_weight++){
    // check if value is in table
    int s_weight_i = hash_table_retrieve(ht,s_weight);
    // remove it
    if(s_weight_i != -1){
      // this weight exists
      hash_table_remove(ht, s_weight);
      int l_weight = limit - s_weight;
      int l_weight_i = hash_table_retrieve(ht,l_weight);
      if(l_weight_i != -1){
        // this is the answer
        return create_answer(l_weight_i, s_weight_i);
      }
    }
  }
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1); // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer *answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2); // {1, 0}

  // TEST 3
  int weights_3[] = {6, 4, 10, 15, 16};
  Answer *answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3); // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4); // {6, 2}

  return 0;
}

#endif
