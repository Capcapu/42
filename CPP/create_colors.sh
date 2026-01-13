#!/bin/bash

# Script pour créer le fichier colors.h dans le répertoire courant
# Usage: ./create_colors.sh

USER_NAME=$(whoami)
CURRENT_DATE=$(date "+%Y/%m/%d %H:%M:%S")

cat > "colors.h" << EOF
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ${USER_NAME} <${USER_NAME}@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ${CURRENT_DATE} by ${USER_NAME}           #+#    #+#             */
/*   Updated: ${CURRENT_DATE} by ${USER_NAME}          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
#define COLORS_H

// Couleurs pour les messages de debug
#define GREEN_LIGHT "\033[92m"
#define GREEN       "\033[32m"
#define PURPLE      "\033[95m"
#define RED         "\033[31m"
#define YELLOW      "\033[93m"
#define BLUE        "\033[94m"
#define CYAN        "\033[96m"
#define MAGENTA     "\033[95m"
#define WHITE       "\033[97m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"
#define RESET       "\033[0m"

#endif
EOF

echo "✅ Fichier colors.h créé avec succès dans $(pwd)"
echo "💡 Vous pouvez maintenant inclure #include \"colors.h\" dans vos fichiers .cpp"
