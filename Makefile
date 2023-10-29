# Nome do projeto
PROJECT = PROJETOAPA

# Diretório de código-fonte
SRCDIR = .

# Diretório de saída
BINDIR = bin

# Diretório de objetos
OBJDIR = obj

# Extensão dos arquivos fonte
SRCEXT = cpp

# Compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -Wall -std=c++11

# Nome do arquivo executável
TARGET = $(PROJECT)

# Encontra todos os arquivos-fonte no diretório SRCDIR com a extensão SRCEXT
SRC_FILES = $(wildcard $(SRCDIR)/*.$(SRCEXT))

# Gera os nomes dos arquivos-objeto com base nos arquivos-fonte
OBJ_FILES = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRC_FILES:.$(SRCEXT)=.o))

# Regra padrão, que irá construir o programa
all: $(BINDIR)/$(TARGET)

# Regra para criar diretórios de saída e objetos
$(BINDIR)/$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BINDIR)
	$(CXX) -o $@ $^

# Regra para compilar os arquivos-fonte em arquivos-objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Limpando arquivos-objeto e executável
clean:
	$(RM) -r $(BINDIR)
	$(RM) -r $(OBJDIR)

# Executa o programa alvo
run: $(BINDIR)/$(TARGET)
	./$<

.PHONY: all clean run
