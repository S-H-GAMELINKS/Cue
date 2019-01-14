<template>
    <div class="container">
        <form>
            <div class="form-group">
                <label>Tittle</label>
                <input class="form-control" v-model="title" placeholder="Input your scaffold title ......">
            </div>
            <div class="form-group">
                <label>Content</label>
                <vue-editor v-model="content" :editorOptions="editorSettings">
                </vue-editor>
            </div>
            <div class="form-group">
                <label>Hashtag</label>
                <input v-model="hashtags">
            </div>
        </form>
        <p>
            <button type="button" class="btn btn-primary" v-if="creatable" v-on:click="createScaffold">Create</button>
            <button type="button" class="btn btn-primary" v-if="editable" v-on:click="editScaffold">Update</button>
        </p>
    </div>
</template>

<script>
import axios from 'axios';
import $ from 'jquery'

export default {
    data: function() {
        return {
            title: "",
            content: ""
        }
    },
    components: {
        VueEditor
    },
    mounted: function() {
        this.checkAddress();
        if(this.editable) {
            this.getScaffold();
            this.getHashTags();
        }
    },
    methods: {
        checkAddress: function() {
            const url = String(this.$route.path);
            if(url.match(/edit/)) {
                this.editable = true;
            } else {
                this.creatable = true;
            }
        },
        getScaffold: function() {
            const id = String(this.$route.path).replace(/\/scaffold\//, '').replace(/\/edit/, '');

            axios.get('/api/scaffolds/' + id).then((response) => {
                this.title = response.data.title;
                this.content = response.data.content;
            }, (error) => {
                alert(error);
            })
        },
        createScaffold: function() {
            const place_id = String(this.$route.path).replace(/\/scaffolds\//, '').replace(/\/edit/, '');

            axios.post('/api/scaffolds', {scaffold: {title: this.title, content: this.content}}).then((response) => {
                if (this.title === "" || this.content === "") {
                    alert("Can't be black in Title or Content!!");
                } else {
                    alert("Success!");
                    this.$router.push({name: 'scaffolds_show'});
                }
            }, (error) => {
                alert(error);
            })
        },
        editScaffold: function() {
            const id = String(this.$route.path).replace(/\/scaffold\//, '').replace(/\/edit/, '');

            axios.put('/api/scaffolds/' + id, {scaffold: {title: this.title, content: this.content}}).then((response) => {
                if (this.title === "" || this.content === "") {
                    alert("Can't be black in Title or Content!!");
                } else {
                    alert("Success!");
                    this.$router.push({name: 'places_show'});
                }
            }, (error) => {
                alert(error);
            })
        }
    }
}
</script>