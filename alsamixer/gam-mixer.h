/*
 *  (gtk-alsamixer) An ALSA mixer for GTK
 *
 *  Copyright (C) 2001-2005 Derrick J Houy <djhouy@paw.za.org>.
 *  Copyright (C) 2022 Sergios - Anestis Kefalidis <sergioskefalidis@gmail.com>.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

#ifndef __GAM_MIXER_H__
#define __GAM_MIXER_H__

#include <alsa/asoundlib.h>
#include <gtk/gtk.h>
#include <gtk/gtksizegroup.h>
#include <alsamixer/gam-app.h>

typedef struct _GamSlider GamSlider;
typedef struct _GamToggle GamToggle;

G_BEGIN_DECLS

#define GAM_TYPE_MIXER            (gam_mixer_get_type ())
#define GAM_MIXER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GAM_TYPE_MIXER, GamMixer))
#define GAM_MIXER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GAM_TYPE_MIXER, GamMixerClass))
#define GAM_IS_MIXER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GAM_TYPE_MIXER))
#define GAM_IS_MIXER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GAM_TYPE_MIXER))
#define GAM_MIXER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GAM_TYPE_MIXER, GamMixerClass))

typedef struct _GamMixerPrivate GamMixerPrivate;
typedef struct _GamMixer GamMixer;
typedef struct _GamMixerClass GamMixerClass;

struct _GamMixer
{
    GtkVBox parent_instance;

    GamMixerPrivate *priv;
};

struct _GamMixerClass
{
    GtkVBoxClass parent_class;

    void (* display_name_changed) (GtkWidget *w);
    void (* visibility_changed)   (GtkWidget *w);
};

GType                 gam_mixer_get_type          (void) G_GNUC_CONST;
GtkWidget            *gam_mixer_new               (GamApp      *gam_app,
                                                   const gchar *card_id,
                                                   const gchar *style);
const gchar          *gam_mixer_get_mixer_name    (GamMixer    *gam_mixer);
const gchar          *gam_mixer_get_config_name   (GamMixer    *gam_mixer);
gchar                *gam_mixer_get_display_name  (GamMixer    *gam_mixer);
void                  gam_mixer_set_display_name  (GamMixer    *gam_mixer,
                                                   const gchar *name);
gboolean              gam_mixer_get_visible       (GamMixer    *gam_mixer);
void                  gam_mixer_set_visible       (GamMixer    *gam_mixer,
                                                   gboolean     visible);
void                  gam_mixer_show_props_dialog (GamMixer    *gam_mixer);


G_END_DECLS

#endif /* __GAM_MIXER_H__ */
