
<h1>Push_swap by Daniel Oliver</h1>
Push swap is a program where you will recive as parameters a list of numbers and need to sort the numbers using only two stacks and the following rules:<br/><br/>
<strong>sa (swap a)</strong>: Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.<br/>
<strong>sb (swap b)</strong>: Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.<br/>
<strong>ss</strong> : sa and sb at the same time.<br/>
<strong>pa (push a)</strong>: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.<br/>
<strong>pb (push b)</strong>: Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.<br/>
<strong>ra (rotate a)</strong>: Shift up all elements of stack a by 1.
The first element becomes the last one.<br/>
<strong>rb (rotate b)</strong>: Shift up all elements of stack b by 1.
The first element becomes the last one.<br/>
<strong>rr </strong>: ra and rb at the same time.<br/>
<strong>rra (reverse rotate a)</strong>: Shift down all elements of stack a by 1.<br/>
The last element becomes the first one.<br/>
<strong>rrb (reverse rotate b)</strong>: Shift down all elements of stack b by 1.<br/>
The last element becomes the first one.<br/>
<strong>rrr</strong> : rra and rrb at the same time.<br/><br/>
You can find further information on this file:<br/>

[Push_swap pdf](https://github.com/Daniel-0liver/push_swap/blob/main/push_swap.pdf)

<h2>How to use</h2>

```
 Git Clone https://github.com/Daniel-0liver/push_swap.git
 cd push_swap
 make
````
# How to run with the GUI:

![Recording 2023-02-09 at 02 30 09](https://user-images.githubusercontent.com/84101904/217702335-1df9535a-3f04-4dd9-af4d-9b3dab9730b5.gif)
First you need to run the Makefile.
```
make re
```
And then the script.
```
pswapviz.py -p ../push_swap/push_swap -s 100 -g2
```
Where you can change the 100 for the amount of numbers that you want to test.
## All the credits for the visualizer go to [o-reo push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) and [10257 push_swap_viz_kivy](https://github.com/10257/push_swap_viz_kivy)
