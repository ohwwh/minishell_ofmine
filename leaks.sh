while :
do
	leaks $1 | grep error
	sleep 0.5
done