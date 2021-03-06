dzenbar
=======

dzen2 bar \w multiple monitors support.

![qbbr-dzenbar](https://i.imgur.com/QQZwleh.png)

Requirements
------------

 * [lm-sensors](https://github.com/groeck/lm-sensors)
 * [weather-util](http://fungi.yuggoth.org/weather/)
 * [mpc](https://www.musicpd.org/clients/mpc/)

Installation
------------

```bash
cd ~/sft/
git clone git@github.com:qbbr/dzenbar.git
cd dzenbar/
cp .dzenbarrc.dist .dzenbarrc
```

add to .xinitrc

```bash
~/sft/dzenbar/dzenbar &
```

for kill all pids, run scrpt:

```
./killdzenbar
```

Configuration
-------------

see `.dzenbarrc`

Mods
----

 * multi core CPU usage
 * memory usage
 * dev temperature (sensors)
 * fs percent usage / free
 * network interface down/up speed in kB/s
 * weather (weather-util)
 * battery
 * volume (amixer)
 * mpd (mpc)
 * mcabber msg counter (statefile)
 * email counter
 * ping
