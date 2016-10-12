template<class In, class Out>
Out copy(In begin, In end, Out dest)
{
        while (begin != end)
                *dest++ = *begin++;
        return dest;
}
