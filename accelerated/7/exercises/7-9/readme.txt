(difficult) The implementation of nrand in §7.4.4/135 will not work for arguments reater than RAND_MAX. Usually, this restriction
is no problem, because RAND_MAX is often the largest possible integer anyway. Nevertheless, there are implementations under which
RAND_MAX is much smaller than the largest possible integer. For example, it is not uncommon for RAND_MAX to be 32767 (2**15 - 1)
and the largest possible integer to be 2147483647 (2**31 - 1). Reimplement nrand so that it works well for all values of n.
