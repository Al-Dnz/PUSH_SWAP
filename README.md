
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
## TO_DO

- [ ] manage int overflow
- [ ] leaks in GNL
- [ ] quick sort

## STRATEGIES

- 2 lists divided by median value of initial list
- sort li_a in one sens , and li_b in the reverse sens
- at the near end [pb] during x=ft_lstsize(li_b) times
- then [ra] x times to reorder final list
