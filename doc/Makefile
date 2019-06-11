TAG     := $(shell git describe | sed 's/-.*//')
DATE    := $(shell git log -1 --format=%ai $(TAG) | sed 's/-/ /g' | awk '{printf "\\\\newdate{tagDate}{%s}{%s}{%s}\n", $$3, $$2, $$1}')
VERSION := $(shell git describe | sed 's/^[vV]//; s/-.*//')

all: getSeq.tex gs.tex header.tex
	printf "%s\n" $(VERSION) > version.tex
	printf "%s\n" $(DATE)    > date.tex
	latex getSeq
	# bibtex getSeq
	# latex getSeq
	latex getSeq
	dvipdf getSeq
gs.tex: ../src/getSeq.org
	bash ../scripts/org2nw ../src/getSeq.org | noweave -n -index -autodefs c > gs.tex
clean:
	rm -f gs.tex getSeq.pdf
