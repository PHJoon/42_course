{
	"setHPP": {
		"prefix": ">setHPP",
		"body": [
			"#ifndef ${1:${TM_FILENAME_BASE}}_HPP",
			"# define ${1:${TM_FILENAME_BASE}}_HPP",
			"",
			"class ${1:${TM_FILENAME_BASE}}",
			"{",
			"\tprivate:",
			"\tpublic:",
			"\t\t${1:${TM_FILENAME_BASE}}(void);",
			"\t\t${1:${TM_FILENAME_BASE}}(const ${TM_FILENAME_BASE}& src);",
			"\t\tvirtual ~${1:${TM_FILENAME_BASE}}(void);",
			"\t\t${1:${TM_FILENAME_BASE}}& operator=(${TM_FILENAME_BASE} const& rhs);",
			"};",
			"",
			"#endif"
		],
		"description": "create cpp clas"
	},
	"setCPP": {
		"prefix": ">setCPP",
		"body": [
			"#include \"${TM_FILENAME_BASE}.hpp\"",
			"",
			"${TM_FILENAME_BASE}::${TM_FILENAME_BASE}(void)",
			"{\n std::cout << \"${TM_FILENAME_BASE} default constructor called\" << std::endl;\n}",
			"",
			"${TM_FILENAME_BASE}::${TM_FILENAME_BASE}(const ${TM_FILENAME_BASE}& src)",
			"{\n std::cout << \"${TM_FILENAME_BASE} copy constructor called\" << std::endl;\n}",
			"",
			"${TM_FILENAME_BASE}::~${TM_FILENAME_BASE}(void)",
			"{\n std::cout << \"${TM_FILENAME_BASE} destructor called\" << std::endl;\n}",
			"",
			"${TM_FILENAME_BASE}& ${TM_FILENAME_BASE}::operator=(${TM_FILENAME_BASE} const& rhs)",
			"{",
			"\tstd::cout << \"${TM_FILENAME_BASE} copy assignment operator called\" << std::endl;",
			"\tif (this != &rhs)",
			"\t{\n\t}",
			"\treturn *this;",
			"}"
		],
		"description": "basic cpp class"
	},	
	"std::cout": {
		"prefix": ">print_line",
		"body": "std::cout << \"$1\" << std::endl;",
		"description": "print line"
	},
	"tryCatch": {
		"prefix": ">tryCatch",
		"body": "try {\n\n} catch(std::exception &e) {\n\n}",
		"description": "make_try_catch",
	},
	"what_make": {
		"prefix": ">make_what",
		// ${1: ${TM_FILENAME_BASE} }
		//${1: ~~}
		"body": "const char * ${TM_FILENAME_BASE}::${1:NameOfException}::what() const throw {\n\treturn(\"${1:NameOfException}\");\n}",
		"description": "make_what",
	}

}