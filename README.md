# mag-slash
<img src="https://weaknetlabs.com/images/magslashlogo2.png"/><br /<br />
Magnetic Card Swipe Reader String Decoder - This application was written and tested with the POSMATE MSR100 Card swipe ($20 USD http://www.amazon.com/gp/product/B00E85TH9I). Some notes about the hardware:
<ul>
<li>Does not function properly in Oracle VirtualBox, Works perfectly in VMWare Player, Weakerthan Linux 6, and even Windows</li>
<li>Is recognized as a human input device, like a keyboard</li>
</ul>
# Functions
This application is written in C, with no extra libraries besides the standard input-output libarary.<br />
<ul>
<li>Reads credit cards (VISA and Mastercard)</li>
<li>Verifies the cards number using the Luhn Algorithm</li>
<li>Reads financial ID Cards</li>
<li>Detects track errors</li>
</ul>
# Build and Install
<b>Make and Install:</b><br />
<code>root@wt: ~# make clean && make && make install</code><br /><br />
<b>Uninstall:</b><br />
<code>root@wt:~ # make uninstall</code>
