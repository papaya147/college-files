exp = c(50, 150, 250, 350, 450, 550, 650)
fam = c(10, 6, 9, 16, 4, 24, 27)
d = rep(exp, fam)
print(paste("Mean: ", mean(d)))
print(paste("Median: ", median(d)))
print(paste("Mode: ", max(d)))
MDmean = 0
for(i in d){
	MDmean = MDmean + abs(mean(d) - i)
}
print(paste("Mean deviation about mean: ", MDmean / length(d)))
MDmedian = 0
for(i in d){
	MDmedian = MDmedian + abs(median(d) - i)
}
print(paste("Mean deviation about median: ", MDmedian / length(d)))
MDmode = 0
for(i in d){
	MDmode = MDmode + abs(max(d) - i)
}
print(paste("Mean deviation about mode: ", MDmode / length(d)))