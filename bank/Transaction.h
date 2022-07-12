
// one file (hopefully page/pages) per month during current year        

//
typedef struct txn {
// id/date
//      mdy offset from 2015. Assume 128 years (7 bits). 12 months (4 bits), 31 days (5 bits) = 16 bits = 2 bytes. Or if 128years*365days=max_val=46720 which needs same number of bits. 1 byte for txn number per day (5 bits fine)
// amount (signed) 4 bytes
// seller 
// Bank 1 nybble
// account 1 nybble
// method: cc, debit, venmo, zelle, transfer, other     3 bits
// memo
// tags     64 or 32 bit integer
// pointer to receipt photo

} txn;

// before seller and memo: 2 + 1 + 4 + 1 + 4 + 8 ~ 20 bytes
// with pointer and delimiter and assuming 64 bit, this becomes 2 + 1 + 4 + 1 + 4 + 8 + 8 + 4 = 32 bytes
// 4 KB pages? 
// how many txns per month?
// Assume < 256 txn per month ~ 8 txn per day
// 2^12/2^8=2^4
// Even if bumped this up not enough
// Let's not worry about pages
// 

static string serialize(txn);
static txn deserialize(string);
