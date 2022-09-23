# Rawface
<h3>Introduction</h3>
<h4>Rawface is a Linux Software That Translates Any File Into Human Readable 0s And 1s (Binary), And Vise Versa.</h4>
<h3>Examples</h3>
<h5>Suppose That You Have A Python Script, By Executing This Command You Can Turn This Python Script into 0s And 1s (Human Readable Binary)</h4>
<pre>$ rawface script.py -c </pre>
<h5>This Command Will Produce Something Like This</h5>
<pre>0100100101011100010010100101001010101.....</pre>
<h5>So You Just Got A Raw Readable Binary Format Of Your File! (This is How Your Python Script is Stored On The Hard Disk And The Memory)</h5>
<h5>Save The Output Of The Last Command in a different File And Execute This Command</h5>
<pre>$ rawface binary.py -d </pre>
<h5>This Command Will Produce Something Like This</h5>
<pre>print ("Hello Python")  #(Or Any Code You Wrote)</pre>
<h3>Setup, Usage And Some Tips</h3>
<h5>Execute this Command To Install Rawface in Your System</h5>
<pre>$ bash rawface_setup</pre>
<h5>Execute Rawface With No Arguments To Display Usage Message</h5>
<pre>$ rawface</pre>
<h4>Some Tips</h4>
<h5>Compiling Any File Into Human-Readable Binary (ASCII Form Of 0s And 1s) And Storing Output in a new file</h5>
<pre>$ rawface myfile.txt -c > myfile_binary.txt</pre>
<h5>Decompiling Any File From Human-Readable Binary Back To It's Actual Content</h5>
<pre>$ rawface myfile_binary.txt -d > myfile.txt</pre>
<h5>You Can Display Text Files, Media Files, Executable Files, Web Files, All Files in 0s And 1s Using Rawface, And Vice Versa You Can Translate 0s And 1s Into Data Files, Example A Python Hello World Script You Wrote Using 0s And 1s, You Can Decode Those 0s And 1s To It's Actual Meaning...</h5>
<pre>$ python3 -c "$(rawface tests/exec01.py -d)"</pre>
<h5>This Command Will Execute The File <a href="/tests/exec01.py">tests/exec01.py</a>, It's A Python Script Written With 0s And 1s!!</h5>
<h2>And Yeah, That's it!</h2>


# Keep in mind that...
This Software Translates Any File To HUMAN-READABLE BINARY And Vice Versa And Not To Computer Readable Binary (That's Because Computer Readable Binaries Are Not 0s And 1s, It is Electricity in Transistors, There is a ton of videos on youtube about this)! What Does That Mean?<br>
I Mean That 0s And 1s You Read Are ASCII Characters (Every 0 is 48 Or in Computer Binary 00110000, and Every 1 is 49 Or in Computer Binary 00110001)
