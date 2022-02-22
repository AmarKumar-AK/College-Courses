# basic printing
Name="Amar Kumar"
Roll="CED17I029"
echo "My name is $Name and My roll number is $Roll"

# using if else
if [[ -e ex2_ced17i029.sh ]]
then
echo "file exist"
else echo "non empty string"
fi

# extracting substring
echo "My branch is ${Roll:0:3} and Last 3 digit of my roll number is ${Roll:6:3}"

# using for loop
j=1
for i in I am beginner in scripting language.
do 
    echo $j - $i
    ((j++)) 
done

# using while loop
i=0
while [ $i -le 10 ]
do
echo -n " $i"
((i=i+2))
done

# using switch case
echo ""
echo -n "Enter you roll number : "
read num
case $num in
29)
echo "You are Amar Kumar" ;;
*)
echo "You are not Amar Kumar" ;;
esac

# using array
x=(1 2 3 4 5 6)
echo -n "Numbers in array are : "
for i in ${x[@]}
do     
    echo -n " $i"
done

# using function
echo ""
function findAge()
{
((age=2021-$birthYear))
echo "you are $age years old"
}
echo -n "Enter your Birth Year : "
read birthYear
findAge

