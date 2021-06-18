# 42 PUSH_SWAP

## LAUNCH

```
make
```

## GENERATE A RANDOM LIST OF INTEGERS

To set a random number list, exectute the next command line 

```
ARG=$(ruby random_list.rb [min] [max] [n])
```

with 
* [min] the minimum of the range
* [max] the maximum of the range
* [n] the number of value of the integer list

Check your list with the next line:

```
echo $ARG
```

## PUSH_SWAP

```
./push_swap $ARG
```
and you will get all operation to sort the initial stack

## CHECKER
```
./checker {your list of int}
```
and enter teh operation you want : sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

result is OK if your sequence sorts , KO if not.

```
./push_swap {your list of int} | ./checker {your list of int}
```
should return OK if push_swap program if efficient.

## CORRECTION

```
ARG=$(ruby random_list.rb 0 1000 [n]) ; ./push_swap $ARG | ./checker_Mac $ARG ;./push_swap $ARG | ./checker $ARG ;./push_swap $ARG | wc -l
```