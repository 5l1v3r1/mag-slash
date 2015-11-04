# MAG-SLASH
<img src="https://weaknetlabs.com/images/magslashlogo2.png"/><br /<br />
# Hardware
Magnetic Card Swipe Reader String Decoder - This application was written and tested with the POSMATE MSR100 Card swipe ($20 USD http://www.amazon.com/gp/product/B00E85TH9I). Some notes about the hardware:
<ul>
<li>Does not function properly in Oracle VirtualBox, Works perfectly in VMWare Player, Weakerthan Linux 6, and even Windows</li>
<li>Is recognized as a human input device, like a keyboard</li>
</ul>
# Magnetic Strip Data
Some notes about the data on the strip. There are different "tracks" on per strip and there can be a 7 bit track, which can contain alpha-numneric characters, and there can be a 5 bit track which can only contain digits. The details are pulled from the first track,
* Sentinel Character = "%"
* Format code = "B" for financial/bank cards, State abbreviation for ID/LIC
* PAN = Primary Account Number
* FS - Field Separators, for 5 and 7 bit tracks are different:
* 5 bit: "%data(=)data?"
* 7 bit: ;data($|^|=)data?"
* NAME
* FS
* EXPR: YYMM - integers - 4 bytes
* Service Code - NNN - 3 bytes
* CVV1 (NOT CVV2!) - 3 bytes
* END sentinel "?"
* LRC (redundancy Check): 1 byte - I have never seen this yet
# Functions
This application is written in C, with no extra libraries besides the standard input-output libarary.<br />
* Reads credit cards (VISA and Mastercard)
* Verifies the cards number using the Luhn Algorithm
* Reads financial ID Cards
* Detects track errors

# Build and Install
<b>Make and Install:</b><br />
<code>root@wt: ~# make clean && make && make install</code><br /><br />
<b>Uninstall:</b><br />
<code>root@wt:~ # make uninstall</code>
