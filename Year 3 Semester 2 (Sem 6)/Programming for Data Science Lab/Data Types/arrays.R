# [10, -10]
a = 10:-10
a

# similar to range in python
sequence1 = seq(1, 5, by = 0.5)
sequence1
class(sequence1)

# similar to linspace in matlab
sequence2 = seq(1, 4, length.out = 6)
sequence2
class(sequence2)

# convert numeric list to integer list
int_seq1 = as.integer(sequence1)
int_seq1
class(int_seq1)

# list manipulation
unis = c("iit", "vit", "srm")
"vit" %in% unis
"mit" %in% unis
unis = append(unis, "mit")
unis
unis = append(unis, "bits", after = 0)
unis
unis[1:3]
