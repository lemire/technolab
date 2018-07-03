jupyter notebook salaries.ipynb

We need to find gender from first name...

https://github.com/organisciak/names/blob/master/data/us-likelihood-of-gender-by-name-in-2014.csv

https://pypi.org/project/Unidecode/

https://fr.m.wikipedia.org/wiki/Loi_de_Benford

```
git submodule add https://github.com/hakimel/reveal.js.git reveal.js
jupyter nbconvert --to slides salaries.ipynb --reveal-prefix=reveal.js --SlidesExporter.reveal_theme=sky
open salaries.slides.html
```
