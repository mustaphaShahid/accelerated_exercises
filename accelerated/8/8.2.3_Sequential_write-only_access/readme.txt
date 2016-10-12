output iterator

we only need to be able to evaluate
*dest = val
and
dest++. Also logical completeness argues that we should also be able to evaluate ++dest

If we wish to use an iterator exclusively for output, there is an implicit requirement that we not execute ++it
more than once between assignments to *it, or assign a value to *it more than once without incrementing it.

think of "write-once"
