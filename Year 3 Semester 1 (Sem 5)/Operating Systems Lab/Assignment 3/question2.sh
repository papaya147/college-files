echo Enter number of processes:
read processes
echo Enter types of resources:
read resource_types

free_resources=()
assigned=()
required=()

# reading free resources
echo Enter free resources:
read input
read -a free_resources <<< $input

# reading assigned resources
for ((i=0; i<processes; i++))
do
    echo "Enter space-separated assigned resources for process $((i + 1)):"
    read -ra row_input
    assigned+=(${row_input[@]})
done

# reading required resources
for ((i=0; i<processes; i++))
do
    echo "Enter space-separated required resources for process $((i + 1)):"
    read -ra row_input
    required+=(${row_input[@]})
done

completed=()
for ((n=0; n<processes; n++))
do
    # checking if enough resources are available for process
    for ((i=0; i<processes; i++))
    do
        # checking if process already completed
        is_completed=0
        for j in ${completed[@]}
        do
            if ((j == i))
            then is_completed=1
            fi
        done

        
        if ((is_completed == 0))
        then
            completable=1
            for ((x=0; x<resource_types; x++))
            do
                r=`expr $resource_types \* $i + $x`
                if ((assigned[r] + free_resources[x] < required[r]))
                then completable=0
                fi
            done
            if ((completable == 1))
            then 
                for ((x=0; x<resource_types; x++))
                do
                    free_resources[x]=$((free_resources[x] + assigned[r]))
                done
                completed+=($i)
            fi
        fi
    done
done

completed_len=${#completed[@]}

if ((completed_len == processes))
then echo This state is safe and the sequence is ${completed[@]}
else echo This state is unsafe
fi