#include "InvertedIndex.h"
        
bool InvertedIndex::add_tag(string new_tag) {
    tags.push_back(new_tag);
}

bool InvertedIndex::add_txn(/* transaction */);
bool InvertedIndex::add_txns(/* transactions */);
txn InvertedIndex::lookup_txn(/* id */);
bool InvertedIndex::remove_txn(/* id */);
bool InvertedIndex::edit_txn(/* id */);
int InvertedIndex::query(/* string */, /* response pointer */);
int InvertedIndex::flush_cache();
void InvertedIndex::monthly_stats();

