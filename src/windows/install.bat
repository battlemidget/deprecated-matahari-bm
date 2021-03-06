rem Install Matahari services
echo

rem Get the install directory 
set target=%0
set target=%target:\install.bat=%

rem Now remove quotes so we can add them as necessary
set target=%target:"=%

cd "%target%"

rem Now install the agents as services and start them

set agents=hostd networkd serviced sysconfigd
for %%A in (%agents%) do (
  sc delete mh_%%A
  del mh_%%A.exe
  copy srvany.exe mh_%%A.exe
  mh_%%A.exe install "%target%\matahari-qmf-%%A.exe" "%target%"
  sc start mh_%%A
)

rem Remove the old name for the network agent
sc delete mh_netd
