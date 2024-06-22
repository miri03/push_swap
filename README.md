<h1 class="code-line" data-line-start=0 data-line-end=1 ><a id="Push_Swap_0"></a>Push_Swap</h1>
<blockquote>
<p class="has-line-data" data-line-start="2" data-line-end="3">My goal on this project was to write a program named <code>push_swap</code> in C which calculates and displays on the standard output the smallest program, made of Push swap language instructions (sa,sb,pa,pb,ra,rb,rr,rra,rrb,rrr) explained below ,that sorts the integers received as arguments.</p>
</blockquote>
<h2 class="code-line" data-line-start=4 data-line-end=5 ><a id="Rules_4"></a>Rules</h2>
<p class="has-line-data" data-line-start="5" data-line-end="7">• You have 2 stacks named a and b.<br>
• At the beginning:</p>
<ul>
<li class="has-line-data" data-line-start="7" data-line-end="32">The stack a contains a random amount of negative and/or positive numbers<br>
which cannot be duplicated.<br>
• The stack b is empty.<br>
• The goal is to sort in ascending order numbers into stack a. To do so you have the<br>
following operations at your disposal:<br>
◦sa (swap a): Swap the first 2 elements at the top of stack a.<br>
– Do nothing if there is only one or no elements.<br>
◦sb (swap b): Swap the first 2 elements at the top of stack b.<br>
–Do nothing if there is only one or no elements.<br>
◦ss : sa and sb at the same time.<br>
◦pa (push a): Take the first element at the top of b and put it at the top of a.<br>
–Do nothing if b is empty.<br>
◦pb (push b): Take the first element at the top of a and put it at the top of b.<br>
–Do nothing if a is empty.<br>
◦ra (rotate a): Shift up all elements of stack a by 1.<br>
–The first element becomes the last one.<br>
◦rb (rotate b): Shift up all elements of stack b by 1.<br>
–The first element becomes the last one.<br>
◦rr : ra and rb at the same time.<br>
◦rra (reverse rotate a): Shift down all elements of stack a by 1.<br>
–The last element becomes the first one.<br>
◦rrb (reverse rotate b): Shift down all elements of stack b by 1.<br>
–The last element becomes the first one.<br>
◦rrr : rra and rrb at the same time.</li>
</ul>
<h2 class="code-line" data-line-start=32 data-line-end=33 ><a id="Additional_feature_32"></a>Additional feature</h2>
<p class="has-line-data" data-line-start="33" data-line-end="43">I added a program named <code>checker</code> that takes as an argument the stack a formatted as a list of integers,<br>
and if it’s given no arguments it stops and displays nothing.<br>
It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’.<br>
Once all the instructions have been read, the program has to execute them on the stack received as an argument.<br>
• If after executing those instructions, the stack a is actually sorted and the stack b<br>
is empty, then the program must display “OK” on the standard output.<br>
• In every other case, it must display “KO” on the standard output.<br>
• In case of error, you must display “Error” followed by a ’\n’ on the standard error.<br>
Errors include for example: some arguments are not integers,<br>
some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.</p>
<h2 class="code-line" data-line-start=43 data-line-end=44 ><a id="Usage_43"></a>Usage</h2>
<pre><code class="has-line-data" data-line-start="45" data-line-end="48" class="language-sh">make
./push_swap <span class="hljs-number">2</span> <span class="hljs-number">1</span> <span class="hljs-number">3</span> <span class="hljs-number">6</span> <span class="hljs-number">5</span> <span class="hljs-number">8</span>
</code></pre>
<pre><code class="has-line-data" data-line-start="49" data-line-end="58" class="language-sh">sa
pb
pb
pb
sa
pa
pa
pa
</code></pre>
<pre><code class="has-line-data" data-line-start="60" data-line-end="71" class="language-sh">make bonus
./checker <span class="hljs-number">2</span> <span class="hljs-number">1</span> <span class="hljs-number">3</span> <span class="hljs-number">6</span> <span class="hljs-number">5</span> <span class="hljs-number">8</span>
sa
pb
pb
pb
sa
pa
pa
pa
</code></pre>
<pre><code class="has-line-data" data-line-start="73" data-line-end="75" class="language-sh">OK
</code></pre>
