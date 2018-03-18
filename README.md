Abans de res, us heu d'instal·lar git. Per mac, la pàgina és [aquesta](https://git-scm.com/download/mac)
i per windows és [aquesta](https://git-scm.com/download/win).
Es descarrega un instal·lador i l'executeu com qualsevol altre programa. 

Després us feu un compte de [GitHub](https://github.com). Si com a nom d'usuari us podeu posar <nom><cognom>, millor. Fet això, obriu un terminal i feu (el $ no l'escriviu, és per indicar terminal). 

`$ git config --global user.name "_Nom Cognom_"`

`$ git config --global user.email "_correu_"`

Quan tingueu el compte, m'aviseu i em passeu el vostre nom d'usuari i us donaré permisos. 

# Clonar el repositori
Des del terminal o el Finder/Finder per windows, creeu una carpeta allà on vulgueu (en aquesta carpeta hi haurà tot el del lab, així que millor que la poseu en un lloc accessible) que es digui lab-electro (en realitat es pot dir com vulgueu). Si l'heu creat des del Finder/Finder per windows, obriu-la amb el terminal (cd _/path/a/la/carpeta_). Un cop estigueu dins de la carpeta en qüestió, heu de clonar el repositori:

`$ git clone https://github.com/arnaumas/lab-electro.git . <---(el punt és important, no us el deixeu o no funcionarà)`
