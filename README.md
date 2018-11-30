PJSD2018_A4
===========
1 Raspberry Pi, 7 WEMOS devices

##WebServer:
Includes /html/ directory, you can sync it to your Pi with 'rsync -avP ./html/ pi@172.16.0.90:/home/pi/Documents/html', then on your pi 'sudo rsync -avP /home/pi/Documents/html /var/www/html'.
Change the IP-adress or folder locations if necessary. Don't forget to edit the permissions for the JSON file on your Pi, so that the PHP and C++ code can edit it. The simplest, but unsecure way would be 'sudo chmod 777 <json file>'.

##Eclipse project (RaspberryPi++):
To import this project into Eclipse:
*Open Eclipse
*Select File -> Import... -> General -> Projects from Folder or Archive -> Next
*Directory... -> Navigate to .../PJSD2018_A4/RaspberryPi++
*Click finish
If you make a mistake and want to delete the project from Eclipse **make sure to uncheck "Delete project contents on disk"!**

The project should work straight away, although you might have to change the IP-address for your Pi (Project properties -> C/C++ Build -> Settings -> Build steps).
