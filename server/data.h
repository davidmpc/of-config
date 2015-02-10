
/* Copyright (c) 2015 Open Networking Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DATA_H
#define DATA_H 1

#include <libxml/tree.h>

#ifndef OFC_VERBOSITY
#define OFC_VERBOSITY   0
#endif

#include <stdbool.h>
#include "res-map.h"

typedef struct ofconf {
    struct ovsdb_idl *idl;
    unsigned int seqno;
    struct vconn *vconn;
    ofc_resmap_t *resource_map;
} ofconf_t;

/*
 * ovs-data.c
 */

extern ofconf_t *ofc_global_context;

bool ofconf_init(const char *ovs_db_path);

char *get_state_data(xmlDocPtr running);

char *get_config_data(void);

void ofconf_destroy(void);

/*
 * local-data.c
 */

/* store /capable-switch/id value
 * node - /capable-switch/id element node. If NULL, the function deletes id
 */
int ofc_set_switchid(xmlNodePtr node);

/* get stored /capable=switch/id value */
const xmlChar *ofc_get_switchid(void);

#endif /* data.h */