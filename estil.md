# Organització del document
La idea és que hi ha un document base, `informe.tex` que conté el preàmbul (paquets, comandos, etc) per tots els informes. Cada un dels informes hauria d'anar a una carpeta `informes/informe-n` i s'hauria de dir `informe-n.tex`. La primera línia de cada informe hauria de ser `\chapter{<Nom>}`, de manera que dins de l'arxiu base només s'ha de fer `\include{./informe-n/informe-n}` (sense extensió, que sino no funciona). Les figures de cada informe haurien d'anar dins de la carpeta `informes/informe-n/figs`. Això és important sobretot si hi ha figures fetes amb gnuplot. També cal que afegiu `{./informe-n/figs}` dins del comando `\graphicspath{}` que està a `informe.tex`.

# Consells pel LaTeX
## Referències
A qualsevol cosa que hagueu de referenciar poseu-li un `\label{eq/fig/sec:<nom>}` amb `eq`, `fig`, etc. segons convingui (les < i > no cal posar-les, Adri). No és essencial però és útil. A l'hora de referenciar, millor que feu `\cref{eq/fig/sec:<nom>}`. Si feu això automàticament escriurà 'equació (2.1)' o 'taula (2.3)' o el que sigui, així que no cal que ho escriviu vosaltres.  

## Abstracts
Per posar un abstract per a cada informe poseu-lo dins d'un `\begin{resum} <...> \end{resum}` immediatament després de començar cada capítol. 

## Valors amb unitats i incerteses
Per posar un valor amb unitats i sense incertesa feu (no és opcional, us obligo jo) `\SI{<Valor>}{<Unitat>}`. <Valor> pot ser qualsevol nombre. El punt decimal és un punt, no una coma. Per notació científica poseu d o e, és a dir, poseu 3d4 si voleu escriure 3x10^4. I <Unitat> és la unitat corresponent. Per fer producte d'unitats es fa servir un punt. Per exemple, per posar unitats de força (en el supòsit que no vulguessiu posar newtons per algun motiu) `kg.m.s^{-2}`. Us obligo a posar exponents negatius enlloc de fraccions (no us obligo tant com abans, però us obligo bastant). Per posar un nombre amb incertesa hi ha `\data{<Valor>}{<Incertesa>}{<Unitat>}`, que automàticament posa parèntesis, més-menys, etc. Si heu de posar notació científica ha d'anar amb la incertesa, no amb el valor. Com abans, les < i > les poso jo perquè s'entengui millor no cal posar-les. De fet si les poseu el LaTeX us cridarà. 

## Taules, floats
La idea de les figures és que el LaTeX determina el millor lloc on posar-les així que no us agobieu si no surten exactament on les heu posat, just go with the flow. Per això existeixen les referències. Sempre que feu una taula o una figura a la primera línia poseu-hi '\centering \small \sffamily' perquè el format sigui el mateix per tots. El caption de les taules va al principi, el de les figures al final. El label sempre ha d'anar després de la caption, perquè sino esteu referenciant la secció, no la figura.

Per fer taules aquí teniu l'exemple canònic
`\begin{tabular}{SSS}
			\toprule
			{Massa (\si{mg})} & {Intensitat (\si{A})} & {Incertesa en la intensitat (\si{A})} \\
			\midrule
			5 & 2.62d3 & 0.10 \\
			10 & 3.62d4 & 0.18 \\
			15 & 4.49d5 & 0.15 \\
			20 & 5.19d3 & 0.18 \\
			25 & 5.8d2 & 0.3 \\
			\bottomrule
\end{tabular}`
El tipus de columna S fa que els nombres surtin macos. Com amb els nombres amb unitats, podeu posar d o e per a la notació científica, com a la segona columna. `\toprule`, `\midrule`, i `\bottomrule` són per fer línies divisores maques. A la primera fila hi ha els títols de les columnes; estan entre claus perquè el LaTeX entengui que és text i no números.   
