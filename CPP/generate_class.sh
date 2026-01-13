#!/bin/bash

# Script pour générer automatiquement une classe C++ avec forme canonique
# Usage: ./generate_class.sh ClassName

if [ $# -eq 0 ]; then
    echo "Usage: $0 ClassName"
    echo "Example: $0 MyClass"
    exit 1
fi

CLASS_NAME=$1
UPPER_CLASS_NAME=$(echo "$CLASS_NAME" | tr '[:lower:]' '[:upper:]')
LOWER_CLASS_NAME=$(echo "$CLASS_NAME" | tr '[:upper:]' '[:lower:]')

# Obtenir la date actuelle
CURRENT_DATE=$(date "+%Y/%m/%d %H:%M:%S")
USER_NAME=$(whoami)

# Génération du fichier .hpp
cat > "${CLASS_NAME}.hpp" << EOF
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ${CLASS_NAME}.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ${USER_NAME} <${USER_NAME}@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ${CURRENT_DATE} by ${USER_NAME}           #+#    #+#             */
/*   Updated: ${CURRENT_DATE} by ${USER_NAME}          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ${UPPER_CLASS_NAME}_HPP
#define ${UPPER_CLASS_NAME}_HPP

#include <iostream>
#include <string>

class ${CLASS_NAME}
{
	private:
		
	protected:
		
	public:
		${CLASS_NAME}();
		${CLASS_NAME}(const ${CLASS_NAME}& other);
		${CLASS_NAME}& operator=(const ${CLASS_NAME}& other);
		~${CLASS_NAME}();
		

};

#endif
EOF

# Génération du fichier .cpp
cat > "${CLASS_NAME}.cpp" << EOF
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ${CLASS_NAME}.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ${USER_NAME} <${USER_NAME}@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ${CURRENT_DATE} by ${USER_NAME}           #+#    #+#             */
/*   Updated: ${CURRENT_DATE} by ${USER_NAME}          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "${CLASS_NAME}.hpp"
#include "colors.h"

${CLASS_NAME}::${CLASS_NAME}()
{
	std::cout << GREEN_LIGHT << "${CLASS_NAME} default constructor called" << RESET << std::endl;
	// Initialiser les attributs ici
}

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other)
{
	std::cout << GREEN_LIGHT << "${CLASS_NAME} copy constructor called" << RESET << std::endl;
	*this = other;
}

${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& other)
{
	std::cout << GREEN_LIGHT << "${CLASS_NAME} copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		// Copier les attributs ici
		// this->_attribute = other._attribute;
	}
	return *this;
}

${CLASS_NAME}::~${CLASS_NAME}()
{
	std::cout << GREEN << "${CLASS_NAME} destructor called" << RESET << std::endl;
	// Libérer les ressources si nécessaire
}


/* Constructeurs supplementaire
${CLASS_NAME}::${CLASS_NAME}(paramètre)
{
	std::cout << GREEN_LIGHT << "${CLASS_NAME} parametric constructor called" << RESET << std::endl;
	// Initialiser avec les paramètres
}
*/


EOF

echo "✅ Fichiers générés avec succès :"
echo "   📄 ${CLASS_NAME}.hpp"
echo "   📄 ${CLASS_NAME}.cpp"

