# season-2-SE-my_curl
<div class="card-block">
<div class="row">
<div class="col tab-content">
<div class="tab-pane active show" id="subject" role="tabpanel">
<div class="row">
<div class="col-md-12 col-xl-12">
<div class="markdown-body">
<p class="text-muted m-b-15">
</p><h1>My Curl</h1>
<p>Remember to git add &amp;&amp; git commit &amp;&amp; git push each exercise!</p>
<p>We will execute your function with our test(s), please DO NOT PROVIDE ANY TEST(S) in your file</p>
<p>For each exercise, you will have to create a folder and in this folder, you will have additional files that contain your work. Folder names are provided at the beginning of each exercise under <code>submit directory</code> and specific file names for each exercise are also provided at the beginning of each exercise under <code>submit file(s)</code>.</p>
<hr>
<table>
<thead>
<tr>
<th>My Curl</th>
<th></th>
</tr>
</thead>
<tbody>
<tr>
<td>Submit directory</td>
<td>.</td>
</tr>
<tr>
<td>Submit files</td>
<td>Makefile - *.c - *.h</td>
</tr>
</tbody>
</table>
<h3>Description</h3>
<p>HTTP Protocol is used everywhere and pretty easy to read, this project will lead you to its world.</p>
<p>You will create a my_curl command (very similar to the UNIX command curl)
my_curl is a tool to get data from a server, using HTTP. The command is designed to work without user interaction.</p>
<p>How does it work?
You send an url as parameter and it will print the html content of a web page.</p>
<p>my_curl only supports HTTP.</p>
<pre class=" language-plain"><code class=" language-plain">$&gt;./my_curl http://www.columbia.edu/~fdc/sample.html
&lt;!DOCTYPE HTML&gt;
&lt;html lang="en"&gt;
&lt;head&gt;
...
&lt;p&gt;
&lt;i&gt;(End)&lt;/i&gt;

&lt;hr&gt;
&lt;/body&gt;  &lt;!-- close the &lt;body&gt; begun above --&gt;
&lt;/html&gt;  &lt;!-- close the &lt;html&gt; begun above --&gt;
</code></pre>
<p>How would you be able to do this magic?
Using <code>sockets</code>. They are file descriptors.</p>
<img src="https://storage.googleapis.com/qwasar-public/s02_SE/network4_thumb_4_.png" width="800px">
<p>HTTP Protocol is pretty straightforward:
<a href="https://www.w3.org/Protocols/rfc2616/rfc2616-sec5.html" target="_blank">RFC HTTP</a></p>
<h2>Authorized functions</h2>
<ul>
<li>bind</li>
<li>connect</li>
<li>socket</li>
<li>write / read</li>
<li>close</li>
<li>select (optional)</li>
</ul>
<h2>Requirements</h2>
<ul>
<li>Your code must be compiled with the flags <strong>-Wall -Wextra -Werror</strong>.</li>
</ul>

<p></p>
</div>

</div>
</div>
</div>
<div class="tab-pane" id="resources" role="tabpanel">
</div>
</div>
</div>
</div>
