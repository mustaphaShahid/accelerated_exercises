forward iterator
'For' needs to support all the operations supported by an input itrator, as well as all the operations supported by an output
iterator.

Moreover, it should not need to meet the single-assignment requirement of output iterators
(since it now makes sense to read the element value after assigning it, and perhaps to change it)
