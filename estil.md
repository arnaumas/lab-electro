# Organització del document
La idea és que hi ha un document base, `informe.tex` que conté el preàmbul (paquets, comandos, etc) per tots els informes. Cada un dels informes hauria d'anar a una carpeta `informes/informe-n` i s'hauria de dir `informe-n.tex`. La primera línia de cada informe hauria de ser `\chapter{<Nom>}`, de manera que dins de l'arxiu base només s'ha de fer `\include{./informe-n/informe-n}` (sense extensió, que sino no funciona. Les figures de cada informe haurien d'anar dins de la carpeta `informes/informe-n/figs`. això és important sobretot si hi ha figures fetes amb gnuplot.  

# Consells pel LaTeX
## Referències
A qualsevol cosa que hagueu de referenciar poseu-li un `\label{eq/fig/sec:<nom>}` amb `eq`, `fig`, etc. segons convingui. No és essencial però és útil. A l'hora de referenciar, millor que feu `\cref{eq/fig/sec:<nom>}`. 

## Abstracts
Per posar un abstract per a cada informe poseu-lo dins d'un `\begin{resum} <...> \end{resum}` immediatament després de començar cada capítol. 

## Valors amb unitats i incerteses
Per posar un valor amb unitats i sense incertesa feu (no és opcional, us obligo jo) `\SI{<Valor>}{<Unitat>}`. <Valor> pot ser qualsevol nombre. El punt decimal és un punt, no una coma. Per notació científica poseu d o e. I <Unitat> és la unitat corresponent. Per fer producte d'unitats es fa servir un punt. Per exemple, per posar unitats de força (en el supòsit que no vulguessiu posar newtons per algun motiu) `kg.m.s^{-2}`. Us obligo a posar exponents negatius enlloc de fraccions (no us obligo tant com abans, però us obligo bastant). Per posar un nombre amb incertesa hi ha `\data{<Valor>}{<Incertesa>}{<Unitat>}`, que automàticament posa parèntesis, més-menys, etc. Si heu de posar notació científica ha d'anar amb la incertesa, no amb el valor.  

