arrival=()
burst=()
priority=()
ready=()
completed=()

echo Enter arrival times:
read input
read -a arrival <<< "$input"

echo Enter burst times:
read input
read -a burst <<< "$input"

echo Enter priority times:
read input
read -a priority <<< "$input"

if [ ${#arrival[@]} -eq ${#burst[@]} ]
then
    arrival_len=${#arrival[@]}

    # selection sort by priority and arrival time
    for((i=0; i<arrival_len-1; i++));
    do
        min=$i
        for ((j=i+1; j<arrival_len; j++))
        do
            if ((priority[j] < priority[min]))
            then min=$j
            fi
            if ((priority[j] == priority[min]))
            then if ((arrival[j] < arrival[min]))
                then min=$j
                fi
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

        # swapping priorities
        temp=${priority[i]}
        priority[i]=${priority[min]}
        priority[min]=$temp
    done
    
    time=${arrival[0]}

    # looping times for number of processes
    for ((n=0; n<arrival_len; n++))
    do
        # building ready queue
        for ((i=0; i<arrival_len; i++))
        do
            if ((arrival[i] <= time))
            then 
                # checking if process is marked completed or already
                process_complete=0
                completed_len=${#completed[@]}
                for ((j=0; j<completed_len; j++))
                do
                    if ((i == completed[j]))
                    then process_complete=1
                    fi
                done
                if ((process_complete == 0))
                then ready+=($i)
                fi
            fi
        done

        # finding min burst time in ready queue
        min_burst=0
        ready_len=${#ready[@]}

        for ((i=0; i<ready_len; i++))
        do
            if ((priority[ready[i]] > priority[ready[min_burst]]))
            then min_burst=$i
            fi
        done

        # displaying process info
        echo $time - $((time + burst[ready[min_burst]])): Process with arrival time: ${arrival[ready[min_burst]]} and burst time: ${burst[ready[min_burst]]} and priority: ${priority[ready[min_burst]]}
        time=$((time + burst[ready[min_burst]]))

        # marking process as completed
        completed+=($((ready[min_burst])))

        # clearing ready queue
        ready=()
    done

else echo Number of values must be equal!
fi