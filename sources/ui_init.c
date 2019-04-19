/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrankly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:05:24 by jfrankly          #+#    #+#             */
/*   Updated: 2019/04/18 19:05:25 by jfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ui_init_2(t_rtui *ui)
{
	kiss_vscrollbar_new(&ui->vscrollbar1, &ui->window1, \
						ui->textbox1.rect.x + ui->textbox_width,
						ui->textbox1.rect.y, ui->textbox_height);
	kiss_label_new(&ui->label_sel, &ui->window1, "Choose file", \
					ui->textbox1.rect.x + kiss_edge, ui->textbox1.rect.y +
					ui->textbox_height + kiss_normal.h);
	kiss_button_new(&ui->button3, &ui->window1, "hide",
					ui->window1.rect.w / 2 - kiss_normal.w / 2 - 20, 460);
	kiss_button_new(&ui->button_light, &ui->window1, "light",
					ui->window1.rect.w / 2 - kiss_normal.w / 2 - 20, 490);
	kiss_button_new(&ui->button_ok1, &ui->window1, "render",
					ui->window1.rect.w / 2 - kiss_normal.w / 2 - 20, 520);
	kiss_button_new(&ui->button_ex, &ui->window1, "exit",
					ui->window1.rect.w / 2 - kiss_normal.w / 2 - 20, 550);
	kiss_window_new(&ui->window3, NULL, 1,
					kiss_screen_width / 2 - ui->window3_width / 2,
					kiss_screen_height / 2 - ui->window3_height / 2,
					ui->window3_width, ui->window3_height);
	kiss_label_new(&ui->label3, &ui->window3, "", ui->window3.rect.x +
					kiss_up.w, ui->window3.rect.y + kiss_vslider.h);
	ui->label3.textcolor = kiss_blue;
	kiss_button_new(&ui->button_light_ok, &ui->window3, "ok",
					ui->window3.rect.w / 2 - kiss_normal.w / 2 - 20, 300);
/* 	kiss_window_new(&ui->window2, NULL, 1,
					kiss_screen_width / 2 - ui->window2_width / 2,
					kiss_screen_height / 2 - ui->window2_height / 2,
					ui->window2_width, ui->window2_height);
	kiss_label_new(&ui->label_res, &ui->window2, "", ui->window2.rect.x +
					kiss_up.w, ui->window2.rect.y + kiss_vslider.h);
	ui->label_res.textcolor = kiss_blue;
	kiss_progressbar_new(&ui->progressbar, &ui->window2,
					ui->window2.rect.x + kiss_up.w - kiss_edge,
					ui->window2.rect.y + ui->window2.rect.h / 2 - kiss_bar.h /
					2 - kiss_border, 160);
	kiss_button_new(&ui->button_ok2, &ui->window2, "OK",
					ui->window2.rect.x + ui->window2.rect.w /
					2 - kiss_normal.w / 2, ui->progressbar.rect.y +
					ui->progressbar.rect.h + 2 * kiss_vslider.h); */
	dirent_read(ui);
	ui->window1.visible = 1;
}

void	ui_init(t_rtui *ui)
{
	ui->textbox_width = 350;
	ui->textbox_height = 300;
	ui->window2_width = 200;
	ui->window2_height = 168;
	ui->window3_width = 300;
	ui->window3_height = 400;
	ui->quit = 0;
	ui->draw = 1;
	ui->renderer = kiss_init("RT", &ui->objects, 400, 600);
	if (!ui->renderer)
		return ;
	kiss_array_new(&ui->a1);
	kiss_array_append(&ui->objects, ARRAY_TYPE, &ui->a1);
	kiss_window_new(&ui->window1, NULL, 1, 0, 0,
					kiss_screen_width, kiss_screen_height);
	ui->label.textcolor.r = 255;
	kiss_textbox_new(&ui->textbox1, &ui->window1, 1, &ui->a1, 30,
					3 * kiss_normal.h, ui->textbox_width, ui->textbox_height);
	ui_init_2(ui);
}
