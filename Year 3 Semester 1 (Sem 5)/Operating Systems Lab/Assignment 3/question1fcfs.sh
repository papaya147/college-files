arrival=()
burst=()

echo Enter arrival times:
read input
read -a arrival <<< "$input"

echo Enter burst times:
read input
read -a burst <<< "$input"

if [ ${#arrival[@]} -eq ${#burst[@]} ]
then
    arrival_len=${#arrival[@]}

    # selection sort by arrival time
    for((i=0; i<arrival_len-1; i++));
    do
        min=$i
        for ((j=i+1; j<arrival_len; j++))
        do
            if ((arrival[j] < arrival[min]))
            then min=$j
            fi
        done

        # swapping arrival time
        temp=${arrival[i]}
        arrival[i]=${arrival[min]}
        arrival[min]=$temp

        # swapping burst times
        temp=${burst[i]}
        burst[i]=${burst[min]}
        burst[min]=$temp
    done
    
    time=${arrival[0]}

    # display no process if time doesnt start at 0
    if ((time != 0))
    then echo 0 - $time: No process in ready queue
    fi

    # display results
    for i in ${!arrival[@]}
    do
        echo $time - $((time + burst[i])): Process with arrival time: ${arrival[i]} and burst time: ${burst[i]}
        time=$((time + burst[i]))
    done

else echo Number of values must be equal!
fi