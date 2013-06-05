
svg_files = $(wildcard *.svg)
png_files = $(svg_files:.svg=.png)

%.png : %.svg
	inkscape --export-png=$@ $< --export-width=1600

%.pdf : %.svg
	inkscape --export-pdf=$@ $<

all : $(png_files)
	echo "done"

