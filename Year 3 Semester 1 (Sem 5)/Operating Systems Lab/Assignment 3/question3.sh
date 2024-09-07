semaphore=1

wait(){
    while ((semaphore <= 0)) 
    do semaphore=$semaphore # do nothing
    done
    semaphore=$((semaphore - 1))
    sleep 5 # simulating process working
    signal
}

signal(){
    semaphore=$((semaphore + 1))
}

# executing process 1
echo Started process 1...
wait
echo Process 1 completed.
echo ""

# wait and then execute process 2
echo Started process 2...
wait
echo Process 2 completed.