# Rawface
<h3>Introduction</h3>
<h4>Rawface is a Linux Software That Translates Any File Into Human Readable 0s And 1s (Binary), And Vise Versa.</h4>
<h3>Examples</h3>
<h4>Suppose That You Have A Python Script, By Executing This Command You Can Turn This Python Script into 0s And 1s (Human Readable Binary)</h4>
<pre>$ rawface script.py -c </pre>
<h4>This Command Will Produce Something Like This</h4>
<pre>0100100101011100010010100101001010101.....</pre>
<h4>So You Just Got A Raw Readable Binary Format Of Your File! (This is How Your Python Script is Stored On The Hard Disk And The Memory)</h4>
<h4>Save The Output Of The Last Command in a different File And Execute This Command</h4>
<pre>$ rawface binary.py -d </pre>
<h4>This Command Will Produce Something Like This</h4>
<pre>print ("Hello Python")  #(Or Any Code You Wrote)</pre>
