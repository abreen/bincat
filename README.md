`bincat` is a simple program that, given one or more files, prints the bits
of each byte in a file on one line. `bincat` outputs one line per file, and
does not print spaces between sequences of eight bits or any other
characters.

`bincat` is a small program written in the spirit of the UNIX philosophy.
For this reason, it is written to be efficient and to be as general a tool
as possible. For example, if you want to see the binary values of each
byte in a file on its own line, you can pipe the output of `bincat` to
the `fold` program on your favorite shell:

    bincat myfile.txt | fold -w 8

`bincat` is also useful for viewing "packed" binary data. If you have a
binary file containing sequences of 5 bits, for example, you could use
`bincat` and `fold` in a manner similar to the above, by specifying that
`fold` use a column width of 5.
