#include "Transaction.h"
#include <vector>
#include <string>

class InvertedIndex {

    public:
        bool add_tag(string new_tag);
        bool add_txn(/* transaction */);
        bool add_txns(/* transactions */);
        txn lookup_txn(/* id */);
        bool remove_txn(/* id */);
        bool edit_txn(/* id */);
        int query(/* string */, /* response pointer */);
        int flush_cache();
        void monthly_stats();
        void yearly_stats();
        

    private:
        vector<string> tags;
        // array of lists of transactions indexed by tags
        // could do hash map, but a simple lookup table is probably faster for small number of tags (< 100? could test, but architecture dependent probably)
        // tag index lookup table
        // data structure of transactions
        // ordered list would be good for lookup and slow on insert
        // order / index on time? can assume that new entries added in roughly cronological roder
        // can batch insert -- sort to-be-added, then add to larger structure
        // store month in ram
        // yearly statistics
        

};
