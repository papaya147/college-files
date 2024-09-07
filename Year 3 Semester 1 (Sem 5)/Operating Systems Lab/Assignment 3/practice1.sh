echo Enter radius:
read n
area=`expr $n \* $n \* 22 / 7`
circ=`expr 2 \* $n \* 22 / 7`
echo Area is $area
echo Circumference is $circ
