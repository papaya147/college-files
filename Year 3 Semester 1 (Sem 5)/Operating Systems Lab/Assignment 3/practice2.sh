sum=0
echo First 5 natural numbers
for i in 1 2 3 4 5
do
sum=`expr $sum + $i`
echo $i
done
echo The sum is $sum
