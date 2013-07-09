dzenbar
=======

requirements
------------

 * [lm-sensors](http://www.lm-sensors.org/)
 * [weather-util](http://fungi.yuggoth.org/weather/)

installation
------------

```bash
cd ~/sft/
git clone git@github.com:qbbr/dzenbar.git
cd dzenbar/
cp .dzenbarrc.dist .dzenbarrc
```

add to .xinitrc

```bash
cd ~/sft/dzenbar/ && ./dzenbar &
```

overview
--------

[![dzen2](https://lh3.googleusercontent.com/-Vu-kTSNaxS8/TnEzqCJ92TI/AAAAAAAAAd4/3Dh5K2GdjAo/s900/dzen2-bottom-short.png)](https://lh6.googleusercontent.com/-iy-0aq7uagk/TnEwB5whzbI/AAAAAAAAAds/DbEyIYe3G5Q/s1400/dzen2-bottom.png)

 * multi core CPU usage
 * CPU, MB temperature
 * mem percent / free
 * fs percent usage / free
 * network (eth0) down/up speed in kB/s
 * new mail count
 * weather (weather-util)
 * volume
 * mpd
