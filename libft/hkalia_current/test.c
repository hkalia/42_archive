/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalia <hkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:52:57 by hkalia            #+#    #+#             */
/*   Updated: 2016/12/06 10:42:53 by hkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

int main() {
  UT_array *nums;
  int i, *p;

  utarray_new(nums,&ut_int_icd);
  for(i=0; i < 10; i++) utarray_push_back(nums,&i);

  for(p=(int*)utarray_front(nums);
      p!=NULL;
      p=(int*)utarray_next(nums,p)) {
    printf("%d\n",*p);
  }

  utarray_free(nums);

  return 0;
}
