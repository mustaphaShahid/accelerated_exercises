if 'string s' is outside while loop it crashes upon the condition that the left vector is smaller than the right vector.
This is because when it skips if "(i != left.size()) s = left[i++]" s will have size of previous left + right which will
 make width1 - s.size() give negative number this will crash program
