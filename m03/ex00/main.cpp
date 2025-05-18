/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:13:52 by gnyssens          #+#    #+#             */
/*   Updated: 2025/05/19 00:22:22 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap premier;
	ClapTrap second("Second");
	ClapTrap troisieme(second);

	premier.attack("Target");
    second.takeDamage(5);
    second.beRepaired(10);
	troisieme.attack("qqn");
    troisieme.takeDamage(15);

	return 0;
}