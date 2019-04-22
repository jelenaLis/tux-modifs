How to 

- go to https://launchpad.net/ubuntu/trusty/+source/extremetuxracer
- download extremetuxracer_0.4.orig.tar.gz,extremetuxracer_0.4-5ubuntu1.diff.gz, extremetuxracer_0.4-5ubuntu1.dsc 
- put them in a folder called, let's say, etracer-src
- install dpkg-dev
- inside that run "dpkg-source -x extremetuxracer_0.4-5ubuntu1.dsc" (soft from dpkg-dev package). NB: ignore messages about signatures
- cd newly created extremetuxracer-0.4, run "debuild". Will compile the soft once -- eventually the missing dependencies will be displayed
- rename the the "src" subfolder
- clone this repository in place of src
- copy the ".deps" hidden folder from the old src to the new one
- "make" inside src to update etracer
- one more step mising before starting! download this  https://ftp.igh.cnrs.fr/pub/ubuntu-ports/pool/universe/e/extremetuxracer/extremetuxracer-data_0.4-5ubuntu1_all.deb and replace it with the existing file you have (that is in your etracer-src folder)
- then install it with "sudo dpkg -i name of the downloaded file"
- to assure no updates write "sudo apt-mark hold  extremetuxracer-data"
- use "launch.sh" to run the game

Tested on ubuntu 14.04 and 16.04
