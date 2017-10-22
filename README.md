dzenbar
=======

dzen2 bar with multiplexer

Requirements
------------

 * [lm-sensors](http://www.lm-sensors.org/)
 * [weather-util](http://fungi.yuggoth.org/weather/)

How it work
-----------

![dzen2 multiplexer](https://lh3.googleusercontent.com/-QeQDWYCKcOI/UgDgaj9EdJI/AAAAAAAABO8/WoetCGbTCNY/s502/dzen2_with_multiplexer.png)

Installation
------------

```bash
cd ~/sft/
git clone git@github.com:qbbr/dzenbar.git
cd dzenbar/
cp .dzenbarrc.dist .dzenbarrc
sudo gcc -Wall dmplex.c -o /usr/bin/dmplex
```

add to .xinitrc

```bash
~/sft/dzenbar/dzenbar &
```

Configuration
-------------

see `.dzenbarrc`

Overview
--------

[![dzen2](https://lh3.googleusercontent.com/-Vu-kTSNaxS8/TnEzqCJ92TI/AAAAAAAAAd4/3Dh5K2GdjAo/s900/dzen2-bottom-short.png)](https://lh6.googleusercontent.com/-iy-0aq7uagk/TnEwB5whzbI/AAAAAAAAAds/DbEyIYe3G5Q/s1400/dzen2-bottom.png)

 * multi core CPU usage
 * CPU, MB temperature (sensors)
 * mem percent / free
 * fs percent usage / free
 * network (eth0) down/up speed in kB/s
 * new mail count
 * weather (weather-util)
 * volume
 * battery (acpi)
 * mpd
 * mcabber (statefile)
