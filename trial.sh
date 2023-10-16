read first_name

echo "user entered name $first_name"



a=34

if [ 34 -gt $a ]
then 
	echo "helo"
fi


if [ 34  -lt  31 ]
then 
	echo "nimis"
elif [ 34 -eq 34 ]
then 
	echo "equal"
fi

echo " _________"

for x in  {1..5}
do 
	echo $x
done

echo " _________"


for x in `echo 1 2 3 6 7 8 22`
do 
	echo $x
done

echo " _________"

z=("hello" "nimisH" "nnad")


for x in ${z[@]};
do 
	echo $x
done

echo " _________"


n=7
for (( i=1 ; i<=$n ; i++ )); 
do
    echo $i
done



echo " while _________"


i=4

while [ $i -le 8 ]
do 
	echo $i
	i=$((i+2))
done
