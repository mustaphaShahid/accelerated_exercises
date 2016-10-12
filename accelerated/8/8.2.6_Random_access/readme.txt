random-access iterators
This function relies on the ability to do arithmetic on iterators. it subtracts one iterator from another to obtain an iteger,
and adds an iterator and an integer to obtain another iterator.

Suppose p and q are random-access iterators and n is an integer;

the complete list of additional requirements, beyond thos for bidirectional iterators, is

p + n, p - n, and n + p
p - q
p[n] (equivalent to *(p + n))
p < q, p > q, p <= q, and p >= q

The only algorithm we have used that requires random-access iterators is the *sort* function. The vector and string iterators are
random-access iterators. However, the list iterator is not.
